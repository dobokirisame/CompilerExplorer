#ifndef GETREQUEST_H
#define GETREQUEST_H
#include "Request.h"
#include <QVariant>
#include <map>

namespace compilerExplorer {
namespace network{
class GetRequest : public Request
{
public:
	GetRequest();
	std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
	void addParameter(const QString &parameterName, const QString &parameterValue);
	std::map<QString, QString> parameters() const;
private:
	QString parametersString() const;
private:
	std::map<QString, QString> mParams;
};
}
}
#endif // GETREQUEST_H
