#include "PutJsonRequest.h"
#include <QNetworkRequest>
#include <QJsonDocument>

namespace compilerExplorer {
namespace network{
PutJsonRequest::PutJsonRequest()
	: PostJsonRequest() {

}

void PutJsonRequest::addGetParameter(const QString &parameterName, const QString &parameterValue) {
	mGetParameters.insert({parameterName, parameterValue});
}

void PutJsonRequest::addPostParameter(const QString &parameterName, const QString &parameterValue) {
	mPostParameters.insert({parameterName, parameterValue});
}

std::unique_ptr<QNetworkReply> PutJsonRequest::sendRequest(QNetworkAccessManager *manager) {
	if(address().isEmpty() || !manager)
		return nullptr;
	QNetworkRequest request;
	QUrl url(address());
	url.setQuery(parametersString(mGetParameters));
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setUrl(url);
	return std::unique_ptr<QNetworkReply>(manager->put(request, QJsonDocument(jsonRequest(mPostParameters)).toJson()));
}

QString PutJsonRequest::requestName() const {
	return QObject::tr("PutJsonRequest");
}
}
}


