#include "htmreport.h"

#include <QtWidgets>

namespace {
    QString dateTimeFromDottedString(const QString& dotted)
    {
        int dot = dotted.indexOf(QChar('.'));
        QString decpart = (dot == -1 ? dotted: dotted.left(dot));
        quint32 tm = decpart.toUInt();
        if( tm )
            return QDateTime::fromTime_t(tm).toString("dd MMMM yyyy,  hh:mm:ss");
        return "null";
    }
}

HtmReport::HtmReport(QWidget* parent) 
    : QTextEdit(parent)
{
    setReadOnly(true);
    parentWidget()->resize(parentWidget()->width(),150);
}

HtmReport::~HtmReport()
{}

void HtmReport::refresh()
{
    QTextEdit::clear();
    QTextCursor cursor = textCursor();
    cursor.insertHtml(html_);
}

void HtmReport::clear()
{
    html_.clear();
    QTextEdit::clear();
}

void HtmReport::addTasksList(const TasksListDocument& doc)
{
    QString html = 
"<h2><center><b>"+ doc.title +"</b></center></h2>\
<h3><left>alias: "+ doc.alias + "</left></h3>\
<p><table width=\"100%\" bgcolor=\"#FFFF99\" style=\"font-size:10pt\" cellspacing=\"1\" cellpadding=\"4\">";

    QList<QString>::const_iterator It = doc.tasks.cbegin();
    for(; It !=  doc.tasks.cend(); ++It )
        html += "<tr><td width=\"100%\"><b>" + *It + "</b></td></tr>";
    html_ += html + "</table><p/><br/><p/>";
}

void HtmReport::addTask(const TaskDocument& doc)
{
    parentWidget()->resize(parentWidget()->width(), 150+150*( html_.length()/300 > 3? 3: html_.length()/300));

    QTextCursor cursor = textCursor();

    QString tableH0 = "<table width=\"100%\" bgcolor=\"#FFFF99\" style=\"font-size:12pt\" cellspacing=\"1\" cellpadding=\"4\"><tr>";
    QString tableH1 = "<table width=\"100%\" bgcolor=\"#BBFFDD\" border=\"1\" style=\"font-size:10pt\" cellspacing=\"1\" cellpadding=\"4\"><tr>";
    QString tableH2 = "<table width=\"100%\" bgcolor=\"#DDEEFF\" style=\"font-size:8pt\" cellspacing=\"0\" cellpadding=\"4\"><tr>";
    QString tableH3 = "<table width=\"100%\" bgcolor=\"#99EEFF\" border=\"1\" style=\"font-size:8pt\" cellspacing=\"1\" cellpadding=\"4\"><tr>";
    QString tableD = "</tr></table>";

    QString creationDate = QDateTime::fromTime_t((uint)doc.creationDate).toString("dd MMMM yyyy,   hh:mm:ss");
    QString invitee = doc.invitee.isEmpty() ? tr("none") : doc.invitee;
    QString notes = doc.notes.isEmpty() ? tr("none") : doc.notes;
    QString completed = (doc.completed ? tr("yes") : tr("no"));
    QString remindOnDate = (doc.remindOnDate ? tr("yes") : tr("no"));
    QString onEnter = (doc.remindOnLocation_onEnter ? tr("yes") : tr("no"));

    QString html = 
tableH0 + 
"<td align=\"left\"><b>" + doc.alias + "</b></td>" + 
tableD + tableH1 + 
"<td align=\"center\"><b>" + doc.title + "</b></td>" + 
tableD + tableH2 + 
"<td align=\"left\" width=\"30%\">creationDate</td>\
<td align=\"left\" width=\"70%\"><b>" + creationDate + "</b></td>\
</tr><tr>\
<td>notes</td>\
<td><b>" + notes + "</b></td>\
</tr><tr>\
<td>invitee</td>\
<td><b>" + invitee + "</b></td>\
</tr><tr>\
<td>remindOnDate</td>\
<td><b>" + tr("%1").arg(doc.remindOnDate) + "</b></td>\
</tr><tr>\
<td>completed</td>\
<td><b>" + completed + "</b></td>" + 
tableD + tableH3 + 
"<td align=\"left\" width=\"30%\">remindOnLocation</td>\
<td align=\"left\" width=\"70%\"><b>" + doc.remindOnLocation_description+ "</b></td>" +
tableD + tableH2 +
"<td align=\"left\" width=\"30%\" rowspan=\"2\">coordinates</td>\
<td align=\"left\" width=\"25%\">longitude</td>\
<td align=\"left\" width=\"45%\"><b>" + doc.remindOnLocation_coordinates_x + "</b></td>\
<tr>\
<td align=\"left\" width=\"25%\">latitude</td>\
<td align=\"left\" width=\"45%\"><b>" + doc.remindOnLocation_coordinates_y + "</b></td></tr>" +
tableD + tableH2 +
"<td align=\"left\" width=\"30%\">onEnter</td>\
<td align=\"left\" width=\"70%\"><b>" + onEnter + "</b></td>\
</tr>\
<tr>\
<td align=\"left\" width=\"30%\">radius</td>\
<td align=\"left\" width=\"70%\"><b>" + tr("%1").arg(doc.remindOnLocation_radius) + "</b></td>" +
tableD + tableH2 + 
 "<td align=\"right\">version " + doc.version + "</td>" + 
tableD + "<p/><br/><p/>";

    html_ += html;
}

void HtmReport::applyLoginInfo(const LoginResponseDocument& doc)
{
    setStyleSheet("QTextEdit {background-color: transparent}");
    setFrameStyle(QFrame::NoFrame);

    QString html = 
"<table width=\"100%\" style=\"font-size:10pt\" bgcolor=\"darkgray\">\
<tr><th align=\"center\" style=\"color:#FFFFFF\"><b>" + 
tr("reponse %1, %2").arg(doc.response).arg(statusHTTPToString(doc.response)) + 
"</b></th></tr></table>\
<table width=\"100%\" style=\"font-size:8pt\" cellpadding=\"4\">";

    if( doc.response < 100 || doc.response > 299 ) {
        html += "<tr><td align=\"right\" width=\"30%\">responsedetails</td><td align=\"left\"><b>" + tr("\"%1\"").arg(doc.responsedetails) + "</b></td></tr>";
        html_ += html+"</table>";
        return;
    }

    if(!doc.session.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"20%\">session</td><td align=\"left\"><b>" + doc.session + "</b></td></tr>";
    if(!doc.ws_session.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"20%\">ws_session</td><td align=\"left\"><b>" + doc.ws_session + "</b></td></tr>";
    if(!doc.eventsession.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"20%\">eventsession</td><td align=\"left\"><b>" + doc.eventsession + "</b></td></tr>";

    html += "</table><hr/><table width=\"100%\" style=\"font-size:8pt\" cellpadding=\"4\">";
    if(!doc.userinfo_name.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">name</td><td align=\"left\"><b>" + doc.userinfo_name + "</b></td></tr>";
    if(!doc.userinfo_username.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">username</td><td align=\"left\"><b>" + doc.userinfo_username + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">id</td><td align=\"left\"><b>" + tr("%1").arg(doc.userinfo_id) + "</b></td></tr>";
    if(!doc.userinfo_firstname.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">firstname</td><td align=\"left\"><b>" + doc.userinfo_firstname + "</b></td></tr>";
    if(!doc.userinfo_lastname.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">lastname</td><td align=\"left\"><b>" + doc.userinfo_lastname + "</b></td></tr>";
    if(!doc.userinfo_registration_datetime.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">registration_datetime</td><td align=\"left\"><b>" + dateTimeFromDottedString(doc.userinfo_registration_datetime) + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">confirmed</td><td align=\"left\"><b>" + (doc.userinfo_confirmed?tr("yes"):tr("no")) + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">trial</td><td align=\"left\"><b>" + (doc.userinfo_trial?tr("yes"):tr("no")) + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">extra_devices</td><td align=\"left\"><b>" + tr("%1").arg(doc.userinfo_extra_devices) + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">banned</td><td align=\"left\"><b>" + (doc.userinfo_banned?tr("yes"):tr("no")) + "</b></td></tr>";
    if( doc.userinfo_banned && !doc.userinfo_ban_reason.isEmpty() )
        html += "<tr><td align=\"right\" width=\"30%\">ban_reason</td><td align=\"left\"><b>" + doc.userinfo_ban_reason + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">balance_paid</td><td align=\"left\"><b>" + doc.userinfo_balance_paid + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">balance_rewards</td><td align=\"left\"><b>" + doc.userinfo_balance_rewards + "</b></td></tr>";
    if( !doc.userinfo_subscription.isEmpty() )
        html += "<tr><td align=\"right\" width=\"30%\">subscription</td><td align=\"left\"><b>" + doc.userinfo_subscription + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">need_confirmation</td><td align=\"left\"><b>" + (doc.userinfo_need_confirmation?tr("yes"):tr("no")) + "</b></td></tr>";
    if(!doc.userinfo_confirmation_datetime.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">confirmation_datetime</td><td align=\"left\"><b>" + dateTimeFromDottedString(doc.userinfo_confirmation_datetime) + "</b></td></tr>";
    if(!doc.userinfo_lastlogin.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">lastlogin</td><td align=\"left\"><b>" + dateTimeFromDottedString(doc.userinfo_lastlogin) + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"30%\">need_confirmation</td><td align=\"left\"><b>" + (doc.userinfo_firstlogin?tr("yes"):tr("no")) + "</b></td></tr>";
    if(!doc.userinfo_login_type.isEmpty()) 
        html += "<tr><td align=\"right\" width=\"30%\">login_type</td><td align=\"left\"><b>" + doc.userinfo_login_type + "</b></td></tr>";
    html += "<tr><td align=\"right\" width=\"20%\">invites_available</td><td align=\"left\"><b>" + (doc.userinfo_invites_available?tr("yes"):tr("no")) + "</b></td></tr>";
    if(!doc.userinfo_autologin_url.isEmpty()) {
        html += 
"</table><hr/><table width=\"100%\" style=\"font-size:8pt\" cellpadding=\"4\">\
<tr><td align=\"left\">autologin_url: <a style=\"color:blue\">" + doc.userinfo_autologin_url + "</a></td></tr>";
    }

    html_ += html + "</table><br/>";
}

QString HtmReport::statusHTTPToString(qint32 status)
{
    QString info = tr("no info");
    switch(status)
    {
    case 100: info = tr("acceptied (continue)"); break;
    case 101: info = tr("acceptied (switching protocols)"); break;
    case 201: info = tr("success (created)"); break;
    case 202: info = tr("success (accepted)"); break;
    case 203: info = tr("success (non-authoritative information)"); break;
    case 204: info = tr("success (no content)"); break;
    case 205: info = tr("success (reset content)"); break;
    case 206: info = tr("success (partial content)"); break;
    case 300: info = tr("redirection (multiple choices)"); break;
    case 301: info = tr("redirection (moved permanently)"); break;
    case 302: info = tr("redirection (moved temporarily)"); break;
    case 303: info = tr("redirection (see other)"); break;
    case 304: info = tr("redirection (not modified)"); break;
    case 305: info = tr("redirection (use proxy)"); break;
    case 306: info = tr("redirection (unused)"); break;
    case 307: info = tr("redirection (temporary redirect)"); break;
    case 401: info = tr("error (unauthorized)"); break;
    case 402: info = tr("error (payment required)"); break;
    case 403: info = tr("error (forbidden)"); break;
    case 404: info = tr("error (not found)"); break;
    case 405: info = tr("error (method not allowed)"); break;
    case 406: info = tr("error (not acceptable)"); break;
    case 407: info = tr("error (proxy authentication required)"); break;
    case 408: info = tr("error (request timeout)"); break;
    case 409: info = tr("error (conflict)"); break;
    case 410: info = tr("error (gone)"); break;
    case 411: info = tr("error (length required)"); break;
    case 412: info = tr("error (precondition failed)"); break;
    case 413: info = tr("error (request entity too large)"); break;
    case 414: info = tr("error (request uri too long)"); break;
    case 415: info = tr("error (unsupported media type)"); break;
    case 416: info = tr("error (requested range not satisfiable)"); break;
    case 417: info = tr("error (expectation failed)"); break;
    case 500: info = tr("internal server error"); break;
    case 501: info = tr("server error (not implemented)"); break;
    case 502: info = tr("server error (bad gateway)"); break;
    case 503: info = tr("server error (service unavailable)"); break;
    case 504: info = tr("server error (gateway timeout)"); break;
    case 505: info = tr("server error (HTTP version not supported)"); break;
    default:
        if( status/100 == 1 )
            info = tr("acceptied");
        else if( status/100 == 2 )
            info = tr("success");
        else if( status/100 == 3 )
            info = tr("redirection (not implemented)");
        else if( status/100 == 4 )
            info = tr("error (bad request)");
        else if( status/100 == 5 )
            info = tr("internal server error");
    break;
    }
    return info;
}

