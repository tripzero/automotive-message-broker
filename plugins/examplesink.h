/*
    Copyright (C) 2012  Intel Corporation

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef EXAMPLESINK_H
#define EXAMPLESINK_H

#include "abstractsink.h"


class ExampleSink : public AbstractSink
{

public:
	ExampleSink(AbstractRoutingEngine* engine);
	virtual PropertyList subscriptions();
	virtual void supportedChanged(PropertyList supportedProperties);
	virtual void propertyChanged(VehicleProperty::Property property, AbstractPropertyType* value, std::string uuid);
	virtual std::string uuid();
};

class ExampleSinkManager: public AbstractSinkManager
{
public:
	ExampleSinkManager(AbstractRoutingEngine* engine)
	:AbstractSinkManager(engine)
	{

	}

	void setConfiguration(map<string, string> config)
	{
		ExampleSink* sink = new ExampleSink(routingEngine);
		sink->setConfiguration(config);
	}
};

#endif // EXAMPLESINK_H
