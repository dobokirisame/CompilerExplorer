#ifndef GETREQUEST_H
#define GETREQUEST_H
#include "Request.h"
#include <QVariant>
#include <map>
#include "compilerexplorer_global.h"

namespace compilerExplorer {
namespace network{
class COMPILEREXPLORERSHARED_EXPORT GetRequest : public Request
{
public:
	GetRequest();
	std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
	void addParameter(const QString &parameterName, const QString &parameterValue);
	std::map<QString, QString> parameters() const;
	QString requestName() const override;
protected:
	QString parametersString() const;
	QString parametersString(const std::map<QString, QString> &parameters) const;
	QNetworkRequest generateRequest(QNetworkAccessManager *manager) const;
private:
	std::map<QString, QString> mParams;
};
}
}
#endif // GETREQUEST_H
