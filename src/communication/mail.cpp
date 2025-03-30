#include "mail.h"

#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465
#define AUTHOR_EMAIL "atikrosthomesec@gmail.com"
#define AUTHOR_PASSWORD "zwwptzeaujjfxikz"

/*
_sender   :   "Panic Button"
_subject  :   "Panic Button Bildirimi!"
_header   :   "Acil Durum Bildirimi!"
_mailcon  :   "mail içerisinde yazanların tümü, ip ler mesajlar vs vs"
_receiver :   "alıcı kişi"
_email    :   "email adresi"
*/
MailSender::MailSender(String sender, String subject, String header, String mailcontent, String receiver, String email) /* Mail kütüphanesi yapıcı methodu*/
{
  _sender = sender;
  _subject = subject;
  _receiver = receiver;
  _email = email;
  _header = header;
  _mailcontent = mailcontent;
}

bool MailSender::send_email() /* mail gönderimini sağlayan fonksiyon*/
{
  SMTPSession smtp;
  MailClient.networkReconnect(true);
  smtp.debug(1);
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = F("mydomain.net");
  session.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  session.time.gmt_offset = 3;
  session.time.day_light_offset = 0;
  SMTP_Message message;
  message.sender.name = _sender;
  message.sender.email = AUTHOR_EMAIL;
  message.subject = _subject;
  message.addRecipient(_receiver, _email);
  message.addHeader(_header);
  message.html.content = _mailcontent;
  if (!smtp.connect(&session))
    return false;
  if (!MailClient.sendMail(&smtp, &message))
  {
    Serial.println("Error sending Email, " + smtp.errorReason());
    ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());
    return false;
  }
  ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());
  smtp.sendingResult.clear();
  return true;
}

/*
bool MailSender::send_email()
{// eski hali
  MailClient.networkReconnect(true);
  smtp.debug(1);
  ESP_Mail_Session session;
  session.server.host_name = SMTP_HOST;
  session.server.port = SMTP_PORT;
  session.login.email = AUTHOR_EMAIL;
  session.login.password = AUTHOR_PASSWORD;
  session.login.user_domain = F("mydomain.net");
  session.time.ntp_server = F("pool.ntp.org,time.nist.gov");
  session.time.gmt_offset = 3;
  session.time.day_light_offset = 0;
  SMTP_Message message;
  message.sender.name = F(_sender);
  message.sender.email = AUTHOR_EMAIL;
  message.subject = F(_subject);
  message.addRecipient(F(_receiver), F(_email));
  message.addHeader(F(_header));
  message.html.content = _mailcontent;
  if (!smtp.connect(&session))
    return false;
  if (!MailClient.sendMail(&smtp, &message))
  {
    Serial.println("Error sending Email, " + smtp.errorReason());
    ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());
    return false;
  }
  ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());
  smtp.sendingResult.clear();
  return true;
}
*/