local component = require("component")
local sides = require("sides")
local colors = require("colors")
local coroutine = require("coroutine")
local event = require("event")

local drive = "/mnt/b97/data" -- Change this as you need

local rs = component.redstone

local address_bus_1 = sides.back
local address_bus_2 = sides.top
local data_bus = sides.left
local operation_bus = sides.front

local gpu = component.gpu

local memory = {}

-- Bundled IO library

local bundled_io = {}

function bundled_io.to_analog(array)
	if array[0] > 0 then array[0] = 1 end
	if array[1] > 0 then array[1] = 1 end
	if array[2] > 0 then array[2] = 1 end
	if array[3] > 0 then array[3] = 1 end
	if array[4] > 0 then array[4] = 1 end
	if array[5] > 0 then array[5] = 1 end
	if array[6] > 0 then array[6] = 1 end
	if array[7] > 0 then array[7] = 1 end
	if array[8] > 0 then array[8] = 1 end
	if array[9] > 0 then array[9] = 1 end
	if array[10] > 0 then array[10] = 1 end
	if array[11] > 0 then array[11] = 1 end
	if array[12] > 0 then array[12] = 1 end
	if array[13] > 0 then array[13] = 1 end
	if array[14] > 0 then array[14] = 1 end
	if array[15] > 0 then array[15] = 1 end
	return array
end

function bundled_io.bytes_to_bundle(byte1, byte2)
	local array = { }
	array[0] = bit32.lshift(bit32.rshift(bit32.band(byte1, 1), 0), 7)
	array[1] = bit32.lshift(bit32.rshift(bit32.band(byte1, 2), 1), 7)
	array[2] = bit32.lshift(bit32.rshift(bit32.band(byte1, 4), 2), 7)
	array[3] = bit32.lshift(bit32.rshift(bit32.band(byte1, 8), 3), 7)
	array[4] = bit32.lshift(bit32.rshift(bit32.band(byte1, 16), 4), 7)
	array[5] = bit32.lshift(bit32.rshift(bit32.band(byte1, 32), 5), 7)
	array[6] = bit32.lshift(bit32.rshift(bit32.band(byte1, 64), 6), 7)
	array[7] = bit32.lshift(bit32.rshift(bit32.band(byte1, 128), 7), 7)
	array[8] = bit32.lshift(bit32.rshift(bit32.band(byte2, 1), 0), 7)
	array[9] = bit32.lshift(bit32.rshift(bit32.band(byte2, 2), 1), 7)
	array[10] = bit32.lshift(bit32.rshift(bit32.band(byte2, 4), 2), 7)
	array[11] = bit32.lshift(bit32.rshift(bit32.band(byte2, 8), 3), 7)
	array[12] = bit32.lshift(bit32.rshift(bit32.band(byte2, 16), 4), 7)
	array[13] = bit32.lshift(bit32.rshift(bit32.band(byte2, 32), 5), 7)
	array[14] = bit32.lshift(bit32.rshift(bit32.band(byte2, 64), 6), 7)
	array[15] = bit32.lshift(bit32.rshift(bit32.band(byte2, 128), 7), 7)
	return array
end

function bundled_io.to_bundle(int)
	return bundled_io.bytes_to_bundle(bit32.band(bit32.rshift(int, 8), 255), bit32.band(int, 255))
end

function bundled_io.to_bytes(array)
	local byte1, byte2 = 0, 0
	array = bundled_io.to_analog(array)
	byte1 = bit32.bor(byte1, bit32.lshift(array[0], 0))
	byte1 = bit32.bor(byte1, bit32.lshift(array[1], 1))
	byte1 = bit32.bor(byte1, bit32.lshift(array[2], 2))
	byte1 = bit32.bor(byte1, bit32.lshift(array[3], 3))
	byte1 = bit32.bor(byte1, bit32.lshift(array[4], 4))
	byte1 = bit32.bor(byte1, bit32.lshift(array[5], 5))
	byte1 = bit32.bor(byte1, bit32.lshift(array[6], 6))
	byte1 = bit32.bor(byte1, bit32.lshift(array[7], 7))
	byte2 = bit32.bor(byte2, bit32.lshift(array[8], 0))
	byte2 = bit32.bor(byte2, bit32.lshift(array[9], 1))
	byte2 = bit32.bor(byte2, bit32.lshift(array[10], 2))
	byte2 = bit32.bor(byte2, bit32.lshift(array[11], 3))
	byte2 = bit32.bor(byte2, bit32.lshift(array[12], 4))
	byte2 = bit32.bor(byte2, bit32.lshift(array[13], 5))
	byte2 = bit32.bor(byte2, bit32.lshift(array[14], 6))
	byte2 = bit32.bor(byte2, bit32.lshift(array[15], 7))
	return byte1, byte2
end

function bundled_io.to_int(array)
	local int = 0
	array = bundled_io.to_analog(array)
	int = bit32.bor(int, bit32.lshift(array[0], 0))
	int = bit32.bor(int, bit32.lshift(array[1], 1))
	int = bit32.bor(int, bit32.lshift(array[2], 2))
	int = bit32.bor(int, bit32.lshift(array[3], 3))
	int = bit32.bor(int, bit32.lshift(array[4], 4))
	int = bit32.bor(int, bit32.lshift(array[5], 5))
	int = bit32.bor(int, bit32.lshift(array[6], 6))
	int = bit32.bor(int, bit32.lshift(array[7], 7))
	int = bit32.bor(int, bit32.lshift(array[8], 8))
	int = bit32.bor(int, bit32.lshift(array[9], 9))
	int = bit32.bor(int, bit32.lshift(array[10], 10))
	int = bit32.bor(int, bit32.lshift(array[11], 11))
	int = bit32.bor(int, bit32.lshift(array[12], 12))
	int = bit32.bor(int, bit32.lshift(array[13], 13))
	int = bit32.bor(int, bit32.lshift(array[14], 14))
	int = bit32.bor(int, bit32.lshift(array[15], 15))
	return int
end

-- actual code

function get_address()
	return bit32.bor(bundled_io.to_int(rs.getBundledInput(address_bus_1)), bit32.lshift(bundled_io.to_int(rs.getBundledInput(address_bus_2)), 16))
end

function poll_signals()
	if rs.getBundledInput(operation_bus, colors.white) > 0 then -- Single byte memory read operation

		local address = get_address()
		if memory[address] ~= nil then
			rs.setBundledOutput(data_bus, bundled_io.bytes_to_bundle(memory[address], 0))
		else
			rs.setBundledOutput(data_bus, bundled_io.bytes_to_bundle(0, 0))
		end

	elseif rs.getBundledInput(operation_bus, colors.orange) > 0 then -- Single word memory read operation

		local address = bundled_io.to_int(rs.getBundledInput(address_bus))
		if memory[address] ~= nil then
			if memory[address + 1] ~= nil then
				rs.setBundledOutput(data_bus, bundled_io.bytes_to_bundle(memory[address], memory[address + 1]))
			else
				rs.setBundledOutput(data_bus, bundled_io.bytes_to_bundle(memory[address], 0))
			end
		else
			if memory[address + 1] ~= nil then
				rs.setBundledOutput(data_bus, bundled_io.bytes_to_bundle(0, memory[address + 1]))
			else
				rs.setBundledOutput(data_bus, bundled_io.bytes_to_bundle(0, 0))
			end
		end

	elseif rs.getBundledInput(operation_bus, colors.magenta) > 0 then -- Single byte memory write operation

		local address = get_address()
		memory[address] = bit32.band(bundled_io.to_int(rs.getBundledInput(data_bus)), 255)

	elseif rs.getBundledInput(operation_bus, colors.lightblue) > 0 then -- Single word memory write operation

		local address = get_address()
		memory[address] = bit32.band(bundled_io.to_int(rs.getBundledInput(data_bus)), 255)		 -- 0000 0000 1111 1111
		memory[address + 1] = bit32.band(bundled_io.to_int(rs.getBundledInput(data_bus)), 65280) -- 1111 1111 0000 0000
																								 -- Hope I didn't mess up the endianness
	else

		rs.setBundledOutput(data_bus, bundled_io.bytes_to_bundle(0, 0))
		
	end
end

-- zero out graphics memory

for i=2048,18047 do
	memory[i] = 0
end

-- load bootloader into memory

local file = io.open(drive, "r")
if not file then
	print("Could not open drive!")
	return
end
for i=18048,18579 do
	memory[i] = string.byte(file:read(1))
end
file:close()

while true do

	for y=0,49 do
		for x=0,159 do
			local char = string.char(memory[2048 + (y * 320) + (x * 2)])
			local _colors = memory[2048 + (y * 320) + (x * 2) + 1]
			local foreground = bit32.band(_colors, 15)
			local background = bit32.band(bit32.rshift(_colors, 4), 15)
			gpu.setForeground(foreground, true)
			gpu.setBackground(background, true)
			gpu.set(x, y, char)
			poll_signals()
		end
	end

	event.pull(0.01)
end
