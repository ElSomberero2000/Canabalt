// library includrs
#include <assert.h>

//project includes
#include "AssetManager.h"

// initialise the static reference to our instance - to nullptr
AssetManager* AssetManager::s_instance = nullptr;

// constructor
AssetManager::AssetManager()
	: m_textures()
	; m_soundBuffers()
	, m_fonts()

{
	// throw an error and stop exectution (in dubug mofr) if a copy
	// of this class has already been made
	assert(s_instance == nullptr)

		// assign ourselves to the instance opinter
			// - this is the new instance of that class that he has just created
		s_instance = this;

}


sf::Texture& AssetManager::GetTexture(std::string _fileName)
{
	// create an iterator to hold key and value pair
	// nd search for the required key
	// using the passed in file name
	auto keyValuePair = s_instance->m_textures.find(_fileName);
	// "auto" in this case is equivalent to writing std::map<std::string
	// ,sf::Texture>iterator
	// this keyword (auto) can be used in cases where the 
	// complier can figure out the type of a variable for you
	// YOU ARE NOT ALLOWED TO USE THIS EXCEPT FOR ITERATORS

	// did we find the texture (aka was it already loaded?)
	// (iterator will be at the end if we did not find it
	if (keyValuePair != s_instance->m_textures.end())
	{
		// yes we found it!
		return keyValuePair->second;

	}
	else
	{

		// no we didnt find it!

		// lets create it then!

		// create a new key value pair using the filename
		// the subscript [] operator creates an entry in 
		// the map if there is not already one there

		sf::Texture& texture = s + instance->m_textures[_fileName]
			// blank texture has been created 
			// now just load it from file using sfml
			texture.loadFromFile(_fileName);

		// return the texture

	}
}