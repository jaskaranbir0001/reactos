#ifndef __BACKEND_H
#define __BACKEND_H

#include "../rbuild.h"

class Backend;

typedef Backend* BackendFactory ( Project& project );

class Backend
{
public:
	class Factory
	{
		static std::vector<Factory*>* factories;
		std::string name;

	protected:

		Factory ( const std::string& name_ );

		virtual Backend* operator() ( Project& ) = 0;

	public:
		static Backend* Create ( const std::string& name, Project& project );

	private:
	};

protected:
	Backend ( Project& project );

public:
	virtual void Process () = 0;

protected:
	Project& ProjectNode;
};

#endif /* __BACKEND_H */
