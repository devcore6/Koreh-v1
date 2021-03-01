#pragma once

/*
 * Concept to check if a class has a member called name of type std::string
 */
template<typename T>
concept hasname = requires(T a) {
	{ a.name };
	std::same_as<decltype(a.name), std::string>;
};

/*
 * Finds an object with a specific name within a vector
 */
template<hasname T>
T* find(std::vector<T> vector, std::string name) {
	for(size_t i = 0; i < vector.size(); i++) if(vector[i].name == name) return &vector[i];
	return NULL;
}

/*
 * Finds an object with a specific name within a vector
 * Same as above but for vectors of T*
 */
template<hasname T>
T* find(std::vector<T*> vector, std::string name) {
	for(size_t i = 0; i < vector.size(); i++) if(vector[i]->name == name) return vector[i];
	return NULL;
}

/*
 * Finds an object with a specific name within a vector
 * Same as the first but for vector*s of T
 */
template<hasname T>
T* find(std::vector<T>* vector, std::string name) {
	for(size_t i = 0; i < vector->size(); i++) if(vector->at(i).name == name) return &vector->at(i);
	return NULL;
}

/*
 * Finds an object with a specific name within a vector
 * Same as above but for vector*s of T*
 */
template<hasname T>
T* find(std::vector<T*>* vector, std::string name) {
	for(size_t i = 0; i < vector->size(); i++) if(vector->at(i)->name == name) return vector->at(i);
	return NULL;
}

/*
 * Finds all objects with a specific name within a vector
 */
template<hasname T>
std::vector<T> findall(std::vector<T> vector, std::string name) requires std::copy_constructible<T> {
	std::vector<T> out;
	for(size_t i = 0; i < vector.size(); i++) if(vector[i].name == name) out.push_back(vector[i]);
	return out;
}

/*
 * Finds all objects with a specific name within a vector
 * Same as above but for vectors of T*
 */
template<hasname T>
std::vector<T*> findall(std::vector<T*> vector, std::string name) {
	std::vector<T*> out;
	for(size_t i = 0; i < vector.size(); i++) if(vector[i].name == name) out.push_back(vector[i]);
	return out;
}

/*
 * Finds all objects with a specific name within a vector
 * Same as above but for vector*s of T
 */
template<hasname T>
std::vector<T> findall(std::vector<T>* vector, std::string name) requires std::copy_constructible<T> {
	std::vector<T> out;
	for(size_t i = 0; i < vector->size(); i++) if(vector->at(i).name == name) out.push_back(vector->at(i));
	return out;
}

/*
 * Finds all objects with a specific name within a vector
 * Same as above but for vector*s of T*
 */
template<hasname T>
std::vector<T*> findall(std::vector<T*>* vector, std::string name) {
	std::vector<T> out;
	for(size_t i = 0; i < vector->size(); i++) if(vector->at(i).name == name) out.push_back(vector->at(i));
	return out;
}