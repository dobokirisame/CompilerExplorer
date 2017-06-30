#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H

#include <QObject>

class QNetworkAccessManager;
namespace compilerExplorer {
namespace network{
class Request;

class RequestSender : public QObject
{
	Q_OBJECT
public:
	explicit RequestSender(QObject *parent = nullptr);
public slots:
	QByteArray sendRequest(Request *request) const;
private:
	QNetworkAccessManager *mManager;
};
}
}
#endif // REQUESTSENDER_H
