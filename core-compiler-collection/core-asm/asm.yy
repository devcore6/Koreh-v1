%{ 
    #include <asm.h>

    extern "C" int yylex();
    extern "C" void yyerror(const char *s);

    size_t curline = 1;
%}

%union {
    int64_t                                     ival;
    uint64_t                                    uval;
    double                                      fval;
    std::string*                                sval;
    std::pair<uint8_t, void*>*                  vptr;
    std::vector<std::pair<uint8_t, void*>*>*    vptrvec;
}

%define parse.trace

%start start

%token              EOL                 "end of line"
%token  <ival>      INTVAL              "signed integer"
%token  <uval>      UINTVAL             "unsigned integer"
%token  <fval>      FLOATVAL            "double"
%token  <ival>      INTVAR              "signed integer address"
%token  <uval>      UINTVAR             "unsigned integer address"
%token  <sval>      REGISTER            "register"
%token  <sval>      STRING              "string"

%type   <vptr>      parameter
%type   <vptrvec>   parametergroup

%%

parameter           : INTVAL {
                        int64_t *val = new int64_t($1);
                        $$ = new std::pair<uint8_t, void*>;
                        $$->first = 1;
                        $$->second = (void*)val;
                    }
                    | UINTVAL {
                        uint64_t *val = new uint64_t($1);
                        $$ = new std::pair<uint8_t, void*>;
                        $$->first = 1;
                        $$->second = (void*)val;
                    }
                    | FLOATVAL {
                        double *val = new double($1);
                        $$ = new std::pair<uint8_t, void*>;
                        $$->first = 1;
                        $$->second = (void*)val;
                    }
                    | INTVAR {
                        int64_t *val = new int64_t($1);
                        $$ = new std::pair<uint8_t, void*>;
                        $$->first = 3;
                        $$->second = (void*)val;
                    }
                    | UINTVAR {
                        uint64_t *val = new uint64_t($1);
                        $$ = new std::pair<uint8_t, void*>;
                        $$->first = 3;
                        $$->second = (void*)val;
                    }
                    | REGISTER {
                        $$ = new std::pair<uint8_t, void*>;
                        $$->first = 2;
                        $$->second = (void*)find(registers, *$1);
                    }
                    | STRING {
                        $$ = new std::pair<uint8_t, void*>;
                        $$->first = 4;
                        $$->second = (void*)$1;
                    }

parametergroup      : parameter {
                        $$ = new std::vector<std::pair<uint8_t, void*>*>;
                        $$->push_back($1);
                    }
                    | parameter ',' parametergroup {
                        $$ = $3;
                        $$->push_back($1);
                    }

instructiongroup    : STRING parametergroup ';' EOL {
                        std::vector<instruction_t> instructions = findall(validinstructions, *$1);
                        if(instructions.size() == 0) {
                            std::cerr << "line " << curline << ": " << "Error! Invalid instruction: " << *$1 << std::endl;
                            errors++;
                        } else {
                            size_t argc = 0;
                            while(instructions.size() > 0) {
                                argc = (instructions[0].arg1 > 0 ? 1 : 0) + (instructions[0].arg2 > 0 ? 1 : 0) + (instructions[0].arg3 > 0 ? 1 : 0);
                                if(argc != $2->size()) {
                                    instructions.erase(instructions.begin());
                                    continue;
                                }
                                std::vector<uint8_t> argt = getargt(instructions[0]);
                                for(size_t i = 0; i < argc; i++) if(argt[i] != $2->at(i)->first) {
                                    instructions.erase(instructions.begin());
                                    continue;
                                }
                                break;
                            }
                            if(instructions.size() == 0) {
                                std::cerr << "line " << curline << ": " << "Error! Invalid arguments for instruction: " << *$1 << std::endl;
                                errors++;
                            } else {
                                instruction_t instruction = instructions[0]; // Just so I don't have to constantly type instructions[0]
                                if(instruction.opcode & (1 << 15)) { // 16 byte instruction
                                    if(mode == 32) {
                                        std::cerr << "line " << curline << ": " << "Error! Invalid size for 32-bit mode for instruction: " << *$1 << std::endl;
                                        errors++;
                                    } else {
                                        binarydata.push_back((unsigned char)((instruction.opcode & 0xFF00) >> 8));
                                        binarydata.push_back((unsigned char)(instruction.opcode & 0x00FF));
                                        switch(argc) {
                                            case 1: {
                                                switch($2->at(0)->first) {
                                                    case 1: {
                                                        for(size_t i = 0; i < 6; i++) binarydata.push_back(0);
                                                        uint64_t *val = (uint64_t*)$2->at(0)->second;
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                        break;
                                                    }
                                                    case 2: {
                                                        register_t *val = (register_t*)$2->at(0)->second;
                                                        if(!val) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                            errors++;
                                                        } else {
                                                            uint8_t size = (instruction.opcode >> 13) & 3;
                                                            if(size != val->size) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                                errors++;
                                                            } else {
                                                                binarydata.push_back(val->address);
                                                                for(size_t i = 0; i < 13; i++) binarydata.push_back(0);
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case 3: {
                                                        binarydata.push_back(0xFF);
                                                        for(size_t i = 0; i < 5; i++) binarydata.push_back(0);
                                                        uint64_t *val = (uint64_t*)$2->at(0)->second;
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                        break;
                                                    }
                                                    case 4: {
                                                        for(size_t i = 0; i < 6; i++) binarydata.push_back(0);
                                                        schedulereplace(binarydata.size(), *(std::string*)$2->at(0)->second);
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back(0);
                                                        break;
                                                    }
                                                }
                                                break;
                                            } // argc = 1
                                            case 2: {
                                                switch($2->at(0)->first) {
                                                    /* case 1 doesn't exist here */
                                                    case 2: {
                                                        register_t *reg = (register_t*)$2->at(0)->second;
                                                        if(!reg) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                            errors++;
                                                        } else {
                                                            uint8_t size = (instruction.opcode >> 13) & 3;
                                                            if(size != reg->size) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                                errors++;
                                                            } else {
                                                                binarydata.push_back(reg->address);
                                                            }
                                                        }
                                                        switch($2->at(1)->first) {
                                                            case 1: {
                                                                for(size_t i = 0; i < 5; i++) binarydata.push_back(0);
                                                                uint64_t *val = (uint64_t*)$2->at(1)->second;
                                                                for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                                break;
                                                            }
                                                            case 2: {
                                                                reg = (register_t*)$2->at(1)->second;
                                                                if(!reg) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                                    if(size != reg->size) {
                                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                                        errors++;
                                                                    } else {
                                                                        binarydata.push_back(reg->address);
                                                                        for(size_t i = 0; i < 12; i++) binarydata.push_back(0);
                                                                    }
                                                                }
                                                                break;
                                                            }
                                                            case 3: {
                                                                uint64_t *val = (uint64_t*)$2->at(1)->second;
                                                                binarydata.push_back(0xFF);
                                                                for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                                for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                                break;
                                                            }
                                                            /* case 4 doesn't exist here */
                                                        }
                                                        break;
                                                    }
                                                    case 3: {
                                                        binarydata.push_back(0xFF);
                                                        switch($2->at(1)->first) {
                                                            case 1: {
                                                                if((instruction.opcode & (1 << 14)) && (instruction.opcode & (1 << 13))) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Argument size mismatch for instruction: " << *$1 << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    binarydata.push_back(0);
                                                                    uint64_t *val = (uint64_t*)$2->at(1)->second;
                                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                                }
                                                                break;
                                                            }
                                                            case 2: {
                                                                register_t *reg = (register_t*)$2->at(1)->second;
                                                                if(!reg) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                                    if(size != reg->size) {
                                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                                        errors++;
                                                                    } else {
                                                                        binarydata.push_back(reg->address);
                                                                    }
                                                                }
                                                            }
                                                            /* case 3 doesn't exist here */
                                                            /* case 4 doesn't exist here */
                                                        }
                                                        uint64_t *val = (uint64_t*)$2->at(0)->second;
                                                        for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                        break;
                                                    }
                                                    /* case 4 doesn't exist here */
                                                }
                                                break;
                                            } // argc = 2
                                            case 3: {
                                                // so far argc == 3 only exists for arguments of type 1, 2, 2 so that makes this less complex
                                                register_t *reg = (register_t*)$2->at(1)->second;
                                                if(!reg) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                    errors++;
                                                } else {
                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                    if(size != reg->size) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                        errors++;
                                                    } else {
                                                        binarydata.push_back(reg->address);
                                                    }
                                                }
                                                reg = (register_t*)$2->at(2)->second;
                                                if(!reg) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                    errors++;
                                                } else {
                                                    uint8_t size = (instruction.opcode >> 13) & 3;
                                                    if(size != reg->size) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                        errors++;
                                                    } else {
                                                        binarydata.push_back(reg->address);
                                                    }
                                                }
                                                uint64_t *val = (uint64_t*)$2->at(0)->second;
                                                for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                for(size_t i = 0; i < 8; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (8 * (7 - i)))) >> (8 * (7 - i))));
                                                break;
                                            } // argc = 3
                                            case 0:
                                            default: {
                                                for(size_t i = 0; i < 14; i++) binarydata.push_back(0);
                                                break;
                                            }
                                        }
                                    }
                                } else { // 8 byte instruction
                                    binarydata.push_back((unsigned char)((instruction.opcode & 0xFF00) >> 8));
                                    binarydata.push_back((unsigned char)(instruction.opcode & 0x00FF));
                                    switch(argc) {
                                        case 1: {
                                            switch($2->at(0)->first) {
                                                case 1: {
                                                    for(size_t i = 0; i < 2; i++) binarydata.push_back(0);
                                                    uint64_t *val = (uint64_t*)$2->at(0)->second;
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                    break;
                                                }
                                                case 2: {
                                                    register_t *reg = (register_t*)$2->at(0)->second;
                                                    if(!reg) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                        errors++;
                                                    } else {
                                                        uint8_t size = (instruction.opcode >> 13) & 3;
                                                        if(size != reg->size) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                            errors++;
                                                        } else {
                                                            binarydata.push_back(reg->address);
                                                            for(size_t i = 0; i < 5; i++) binarydata.push_back(0);
                                                        }
                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    binarydata.push_back(0xFF);
                                                    binarydata.push_back(0);
                                                    uint64_t *val = (uint64_t*)$2->at(0)->second;
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                    break;
                                                }
                                                case 4: {
                                                    for(size_t i = 0; i < 2; i++) binarydata.push_back(0);
                                                    schedulereplace(binarydata.size(), *(std::string*)$2->at(0)->second);
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                    break;
                                                }
                                            }
                                            break;
                                        } // argc = 1
                                        case 2: {
                                            switch($2->at(0)->first) {
                                                /* case 1 doesn't exist here */
                                                case 2: {
                                                    register_t *reg = (register_t*)$2->at(0)->second;
                                                    if(!reg) {
                                                        std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                        errors++;
                                                    } else {
                                                        uint8_t size = (instruction.opcode >> 13) & 3;
                                                        if(size != reg->size) {
                                                            std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                            errors++;
                                                        } else {
                                                            binarydata.push_back(reg->address);
                                                        }
                                                    }
                                                    switch($2->at(1)->first) {
                                                        case 1: {
                                                            binarydata.push_back(0);
                                                            uint64_t *val = (uint64_t*)$2->at(1)->second;
                                                            for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                            break;
                                                        }
                                                        case 2: {
                                                            reg = (register_t*)$2->at(1)->second;
                                                            if(!reg) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                errors++;
                                                            } else {
                                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                                if(size != reg->size) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    binarydata.push_back(reg->address);
                                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        case 3: {
                                                            uint64_t* val = (uint64_t*)$2->at(1)->second;
                                                            binarydata.push_back(0xFF);
                                                            for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                            break;
                                                        }
                                                        /* case 4 doesn't exist here */
                                                    }
                                                    break;
                                                }
                                                case 3: {
                                                    binarydata.push_back(0xFF);
                                                    switch($2->at(1)->first) {
                                                        case 1: {
                                                            if((instruction.opcode & (1 << 14)) && (instruction.opcode & (1 << 13))) {
                                                                std::cerr << "line " << curline << ": " << "Error! Argument size mismatch for instruction: " << *$1 << std::endl;
                                                                errors++;
                                                            } else {
                                                                binarydata.push_back(0);
                                                                uint64_t *val = (uint64_t*)$2->at(1)->second;
                                                                for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                            }
                                                            break;
                                                        }
                                                        case 2: {
                                                            register_t *reg = (register_t*)$2->at(1)->second;
                                                            if(!reg) {
                                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                                errors++;
                                                            } else {
                                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                                if(size != reg->size) {
                                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                                    errors++;
                                                                } else {
                                                                    binarydata.push_back(reg->address);
                                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back(0);
                                                                }
                                                            }
                                                            break;
                                                        }
                                                        /* case 3 doesn't exist here */
                                                        /* case 4 doesn't exist here */
                                                    }
                                                    uint64_t *val = (uint64_t*)$2->at(0)->second;
                                                    for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                                    break;
                                                }
                                                /* case 4 doesn't exist here */
                                            }
                                            break;
                                        } // argc = 2
                                        case 3: {
                                            // so far argc == 3 only exists for arguments of type 1, 2, 2 so that makes this less complex
                                            register_t *reg = (register_t*)$2->at(1)->second;
                                            if(!reg) {
                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                errors++;
                                            } else {
                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                if(size != reg->size) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                    errors++;
                                                } else {
                                                    binarydata.push_back(reg->address);
                                                }
                                            }
                                            reg = (register_t*)$2->at(2)->second;
                                            if(!reg) {
                                                std::cerr << "line " << curline << ": " << "Error! Invalid register" << std::endl;
                                                errors++;
                                            } else {
                                                uint8_t size = (instruction.opcode >> 13) & 3;
                                                if(size != reg->size) {
                                                    std::cerr << "line " << curline << ": " << "Error! Invalid operand size for instruction: " << *$1 << std::endl;
                                                    errors++;
                                                } else {
                                                    binarydata.push_back(reg->address);
                                                }
                                            }
                                            uint64_t *val = (uint64_t*)$2->at(0)->second;
                                            for(size_t i = 0; i < 4; i++) binarydata.push_back((unsigned char)((*val & ((uint64_t)0xFF << (4 * (3 - i)))) >> (4 * (3 - i))));
                                            break;
                                        } // argc = 3
                                        case 0:
                                        default: {
                                            for(size_t i = 0; i < 6; i++) binarydata.push_back(0);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        for(size_t i = 0; i < $2->size(); i++) {
                            delete $2->at(i)->second;
                            delete $2->at(i);
                        }
                        delete $2;
                        delete $1;
                    }
                    | STRING ';' EOL {
                        std::vector<instruction_t> instructions = findall(validinstructions, *$1);
                        if(instructions.size() == 0) {
                            std::cerr << "line " << curline << ": " << "Error! Invalid instruction: " << *$1 << std::endl;
                            errors++;
                        } else {
                            size_t argc = 0;
                            while(instructions.size() > 0) {
                                argc = (instructions[0].arg1 > 0 ? 1 : 0) + (instructions[0].arg2 > 0 ? 1 : 0) + (instructions[0].arg3 > 0 ? 1 : 0);
                                if(argc != 0) {
                                    instructions.erase(instructions.begin());
                                    continue;
                                }
                                break;
                            }
                            if(instructions.size() == 0) {
                                std::cerr << "line " << curline << ": " << "Error! Invalid arguments for instruction: " << *$1 << std::endl;
                                errors++;
                            } else {
                                instruction_t instruction = instructions[0]; // Just so I don't have to constantly type instructions[0]
                                if(instruction.opcode & (1 << 15)) { // 16 byte instruction
                                    if(mode == 32) {
                                        std::cerr << "line " << curline << ": " << "Error! Invalid size for 32-bit mode for instruction: " << *$1 << std::endl;
                                        errors++;
                                    } else {
                                        binarydata.push_back((unsigned char)((instruction.opcode & 0xFF00) >> 8));
                                        binarydata.push_back((unsigned char)(instruction.opcode & 0x00FF));
                                        for(size_t i = 0; i < 14; i++) binarydata.push_back(0);
                                    }
                                } else { // 8 byte instruction
                                    binarydata.push_back((unsigned char)((instruction.opcode & 0xFF00) >> 8));
                                    binarydata.push_back((unsigned char)(instruction.opcode & 0x00FF));
                                    for(size_t i = 0; i < 6; i++) binarydata.push_back(0);
                                }
                            }
                        }
                        delete $1;
                    }

label               : STRING ':' EOL {
                        addlabel(*$1);
                        delete $1;
                    }

start               :
                    | start EOL
                    | start label
                    | start instructiongroup

%%

void yyerror(const char *s) {
    std::cerr << "line " << curline << ": " << s << std::endl;
    errors++;
}
