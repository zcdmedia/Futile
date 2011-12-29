/**
	@file		asset.h
	@author		Matthew Hinkle
 */

#ifndef FUTILE_ASSET_H_
#define FUTILE_ASSET_H_

#include <string>

#include <futile/serializable.h>

namespace futile {

/* forward declaration */
class RawBuffer;

/**
	resource abstract class
 */
class Asset : Serializable<Asset *> {
public:
	Asset(const std::string & name) : name(name) { }
	virtual ~Asset() { }

	/* accessors */
	inline const std::string & get_name() const { return this->name; }

	/* mutators */
	inline void set_name(const std::string & name) { this->name = name; }

	/* interfaces */
	virtual RawBuffer * serialize() const = 0;
	virtual Asset * deserialize(const RawBuffer & data) = 0;

private:
	std::string name;

	Asset(const Asset &);
	Asset & operator=(const Asset &);
};

}

#endif
