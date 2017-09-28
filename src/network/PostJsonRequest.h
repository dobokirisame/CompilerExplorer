#ifndef POSTJSONREQUEST_H
#define POSTJSONREQUEST_H
#include "GetRequest.h"
#include <QJsonObject>
#include "compilerexplorer_global.h"

namespace compilerExplorer {
namespace network{

class COMPILEREXPLORERSHARED_EXPORT PostJsonRequest : public GetRequest
{
public:
	PostJsonRequest();
	std::unique_ptr<QNetworkReply> sendRequest(QNetworkAccessManager *manager) override;
	QStringList filters() const;
	void setFilters(const QStringList &filters);
	void setFiltersKey(const QString &filtersKey);
	QString requestName() const override;
protected:
	QJsonObject jsonRequest() const;
	QJsonObject jsonRequest(const std::map<QString, QString> &parameters) const;
private:
	QStringList mFilters;
	QString mFiltersKey;
};
}
}
#endif // POSTJSONREQUEST_H
