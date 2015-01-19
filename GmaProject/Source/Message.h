#pragma once
/*!
 * \class Message.h
 *
 * \brief : holds the types of events messages handled by engine.
 * \author Akshay
 */
class Msg
{
public:
	enum msg_type{
		msg_quit = 0,
		msg_left_pressed,
		msg_right_pressed,
		msg_up_pressed,
		msg_down_pressed,
		msg_left_release,
		msg_right_release,
		msg_up_release,
		msg_down_release,
		msg_debug,
		msg_advanced_debug,
		msg_window_resized,
		msg_help,
		msg_space_pressed,
		msg_lalt_pressed,
		msg_lalt_released
	};

	Msg(msg_type message_type) : type(message_type){};
	~Msg(){};

	// type of the message
	msg_type type;
};