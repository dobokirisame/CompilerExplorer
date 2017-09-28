#ifndef PUTJSONREQUEST_H
#define PUTJSONREQUEST_H
#include "PostJsonRequest.h"
#include <QJsonObject>
#include "compilerexplorer_global.h"

namespace compilerExplorer {
namespace network{

class COMPILEREXPLORERSHARED_EXPORT PutJsonRequest : public PostJsonRequest
{
public:
	PutJsonRequest();
	std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
};
}
}
#endif // PUTJSONREQUEST_H
