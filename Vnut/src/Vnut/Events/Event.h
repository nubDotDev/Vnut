#pragma once

#include "vnutpch.h"

#include "Vnut/Core/Core.h"
#include "Vnut/Utils/Logger.h"

namespace Vnut
{

	// Base Event class
	class VNUT_API Event
	{
	public:
		virtual std::string toString() const { return "Event"; };
	};

	// Handlers

	class HandlerBase
	{
	public:
		virtual void call(Event* event) = 0;
	};

	template<typename T, typename EventType>
	class Handler : public HandlerBase
	{
	public:
		using HandlerFunc = void(T::*)(EventType*);
		Handler(T* inst, HandlerFunc handlerFunc) : m_inst(inst), m_handlerFunc(handlerFunc) {}

		void call(Event* event) override
		{
			(m_inst->*m_handlerFunc)(static_cast<EventType*>(event));
		}
	private:
		T* m_inst;
		HandlerFunc m_handlerFunc;
	};

	// EventBus
	using HandlerList = std::vector<HandlerBase*>;
	using HandlerListMap = std::map<std::type_index, HandlerList*>;
	class VNUT_API EventBus
	{
	public:
		template<typename EventType>
		static void send(EventType* event)
		{
			HandlerList* handlerList = s_handlers[typeid(EventType)];
			if (handlerList == nullptr)
				return;
			for (auto& handler : *handlerList)
				handler->call(event);
		}
		
		template<typename T, typename EventType>
		static void subscribe(T* inst, void(T::*handlerFunc)(EventType*))
		{
			HandlerList* handlerList = s_handlers[typeid(EventType)];
			if (handlerList == nullptr)
			{
				handlerList = new HandlerList();
				handlerList->push_back(new Handler<T, EventType>(inst, handlerFunc));
				s_handlers[typeid(EventType)] = handlerList;
			}
			else
			{
				handlerList->push_back(new Handler<T, EventType>(inst, handlerFunc));
				s_handlers[typeid(EventType)] = handlerList;
			}
		}
	private:
		static HandlerListMap s_handlers;
	};

}