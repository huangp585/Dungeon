#include "Object.h"

Object::Object() {
	name = "empty";
	tag = "empty";
}

Object::Object(string _name, string _tag) {
	name = _name;
	tag = _tag;
}

void Object::setName(string _name) {
	this->name = _name;
}

void Object::setTag(string _tag) {
	this->tag = _tag;
}

string Object::getName() {
	return name;
}

string Object::getTag() {
	return tag;
}