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
//	url.setPort(port());
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	request.setUrl(url);
	return std::unique_ptr<QNetworkReply>(manager->post(request, QJsonDocument(jsonRequest()).toJson()));
}

QJsonObject PostJsonRequest::jsonRequest() const {
	QJsonObject result;
	for(const auto &param : parameters()) {
		result.insert(param.first, param.second);
	}
	return result;
}
}
}
