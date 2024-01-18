
#include "Contact.hpp"

Contact::Contact() : first(""), name(""), nick(""), number(""), secret("")
{

}

void	Contact::set_first(const std::string &s)
{
	this->first = s;
}

void	Contact::set_name(const std::string &s)
{
	this->name = s;
}

void	Contact::set_nick(const std::string &s)
{
	this->nick = s;
}

void	Contact::set_number(const std::string &s)
{
	this->number = s;
}

void	Contact::set_secret(const std::string &s)
{
	this->secret = s;
}

std::string	Contact::get_first() const
{
	return (first);
}

std::string	Contact::get_name() const
{
	return (name);
}

std::string	Contact::get_nick() const
{
	return (nick);
}

std::string	Contact::get_number() const
{
	return (number);
}

std::string	Contact::get_secret() const
{
	return (secret);
}

