#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H

#include <QObject>
#include <memory>
#include "compilerexplorer_global.h"

class QNetworkAccessManager;
namespace compilerExplorer {
namespace network{
class Request;

class COMPILEREXPLORERSHARED_EXPORT RequestSender : public QObject
{
	Q_OBJECT
public:
	explicit RequestSender(QObject *parent = nullptr);
public slots:
	QByteArray sendRequest(const std::unique_ptr<Request> &request) const;
private:
	QNetworkAccessManager *mManager;
};
}
}
#endif // REQUESTSENDER_H
