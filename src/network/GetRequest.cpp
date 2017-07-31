#include "GetRequest.h"
#include <QNetworkRequest>
#include <QUrl>

namespace compilerExplorer {
namespace network{
GetRequest::GetRequest()
    : Request() {

}

std::unique_ptr<QNetworkReply> GetRequest::sendRequest(QNetworkAccessManager *manager) {
	if(address().isEmpty() || !manager)
		return nullptr;
	QNetworkRequest request;
	QUrl url(address());
	if(address().startsWith("https")) {
		manager->connectToHostEncrypted(address());
	}

	url.setQuery(parametersString());

	QSslConfiguration sslConfiguration(QSslConfiguration::defaultConfiguration());
	sslConfiguration.setProtocol(QSsl::SecureProtocols);
	request.setSslConfiguration(sslConfiguration);
	request.setUrl(url);
	return std::unique_ptr<QNetworkReply>(manager->get(request));
}

void GetRequest::addParameter(const QString &parameterName, const QString &parameterValue) {
	mParams.insert({parameterName, parameterValue});
}

QString GetRequest::parametersString() const {
	QString result;
	for(const auto &param : mParams) {
		result.append(param.first);
		result.append('=');
		result.append(param.second);
		result.append('&');
	}
	return result;
}

std::map<QString, QString> GetRequest::parameters() const {
	return mParams;
}

QString GetRequest::requestName() {
	return QObject::tr("GetRequest");
}

}
}
