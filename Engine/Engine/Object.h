#pragma once

#ifndef _OBJECT_H_
#define _OBJECT_H_

class Object 
{
	bool initialized = false;
	std::string name = "";
	int id = 0;

protected:
	Object() = default;
	virtual ~Object() = default;

	virtual void Initialize();
	virtual void Destroy();

public:
	virtual void Load(const json::JSON&);

	bool IsInitialized() const { return initialized; }
	const std::string& GetName() const { return name; }
	int GetId() const { return id; }
};

#endif // !_OBJECT_H_