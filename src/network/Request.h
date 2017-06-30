#ifndef REQUEST_H
#define REQUEST_H
#include <QByteArray>
#include <memory>
#include <QString>
#include <QNetworkReply>

class QNetworkRequest;
class QNetworkAccessManager;
namespace compilerExplorer {
namespace network{
class Request
{
public:
	Request();
	virtual ~Request();
//	virtual QNetworkRequest *request() = 0;
	virtual std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) = 0;
	QString address() const;
	void setAddress(const QString &address);
	int port() const;
	void setPort(int port);

private:
	QString mAddress;
	int mPort;
};
}
}
#endif // REQUEST_H
