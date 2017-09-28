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
	void addGetParameter(const QString &parameterName, const QString &parameterValue);
	void addPostParameter(const QString &parameterName, const QString &parameterValue);
	void addParameter(const QString &parameterName, const QString &parameterValue) = delete;
	std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
	QString requestName() const override;
private:
	std::map<QString, QString> mGetParameters;
	std::map<QString, QString> mPostParameters;
};
}
}
#endif // PUTJSONREQUEST_H
