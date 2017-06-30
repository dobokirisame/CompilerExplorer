#ifndef REQUEST_H
#define REQUEST_H
#include <QByteArray>
#include <memory>

class QNetworkRequest;
class QNetworkAccessManager;
class QNetworkReply;
namespace compilerExplorer {
namespace network{
class Request
{
public:
	Request();
	virtual ~Request();
	virtual QNetworkRequest *request() = 0;
	virtual std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) = 0;
};
}
}
#endif // REQUEST_H
