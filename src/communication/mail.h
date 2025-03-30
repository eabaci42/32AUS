#ifndef MAIL_H
#define MAIL_H

#include <Arduino.h>
#include <ESP_Mail_Client.h>

class MailSender
{
public:
    MailSender(String sender, String subject, String header, String mailcontent, String receiver, String email);
    bool send_email();

private:
    String _sender;
    String _subject;
    String _header;
    String _mailcontent;
    String _receiver;
    String _email;
};
#endif