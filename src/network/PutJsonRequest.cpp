#include "PutJsonRequest.h"

namespace compilerExplorer {
namespace network{
PutJsonRequest::PutJsonRequest()
	: PostJsonRequest() {

}

std::unique_ptr<QNetworkReply> PutJsonRequest::sendRequest(QNetworkAccessManager *manager) {

	if(address().isEmpty() || !manager)
		return nullptr;
	QNetworkRequest request;
	QUrl url(address());
	url.setQuery(parametersString());
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setUrl(url);
	return std::unique_ptr<QNetworkReply>(manager->put(request, QJsonDocument(jsonRequest()).toJson()));
}
}
}
