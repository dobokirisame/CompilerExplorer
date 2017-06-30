#ifndef POSTJSONREQUEST_H
#define POSTJSONREQUEST_H
#include "GetRequest.h"
#include <QJsonObject>

namespace compilerExplorer {
namespace network{

class PostJsonRequest : public GetRequest
{
public:
	PostJsonRequest();
	std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
private:
	QJsonObject jsonRequest() const;
};
}
}
#endif // POSTJSONREQUEST_H
