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
	QStringList filters() const;
	void setFilters(const QStringList &filters);

private:
	QJsonObject jsonRequest() const;
	QStringList mFilters;
};
}
}
#endif // POSTJSONREQUEST_H
