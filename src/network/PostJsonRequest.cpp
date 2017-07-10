#include "PostJsonRequest.h"
#include <QNetworkRequest>
#include <QJsonDocument>

namespace compilerExplorer {
namespace network{

PostJsonRequest::PostJsonRequest()
    : GetRequest() {

}

std::unique_ptr<QNetworkReply> PostJsonRequest::sendRequest(QNetworkAccessManager *manager) {
	if(address().isEmpty() || !manager)
		return nullptr;
	QNetworkRequest request;
	QUrl url(address());
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setUrl(url);
	return std::unique_ptr<QNetworkReply>(manager->post(request, QJsonDocument(jsonRequest()).toJson()));
}

QJsonObject PostJsonRequest::jsonRequest() const {
	QJsonObject result;
	for(const auto &param : parameters()) {
		result.insert(param.first, param.second);
	}
	if(!filters().isEmpty()) {
		QJsonObject enabledFilters;
		for(auto filter : filters()) {
			enabledFilters.insert(filter, "true");
		}
		result.insert(mFiltersKey, enabledFilters);
	}
	return result;
}

QStringList PostJsonRequest::filters() const {
	return mFilters;
}

void PostJsonRequest::setFilters(const QStringList &filters) {
	mFilters = filters;
}

void PostJsonRequest::setFiltersKey(const QString &filtersKey) {
	mFiltersKey = filtersKey;
}

QString PostJsonRequest::requestName() {
	return QObject::tr("PostJsonRequest");
}
}
}
