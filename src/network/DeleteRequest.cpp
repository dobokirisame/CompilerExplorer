#include "DeleteRequest.h"

namespace compilerExplorer {
namespace network{
DeleteRequest::DeleteRequest()
	: GetRequest() {
}

std::unique_ptr<QNetworkReply> DeleteRequest::sendRequest(QNetworkAccessManager *manager) {
	if(address().isEmpty() || !manager)
		return nullptr;
	auto request = generateRequest();
	return std::unique_ptr<QNetworkReply>(manager->deleteResource(request));
}

QString DeleteRequest::requestName() {
	return QObject::tr("DeleteRequest");
}
}
}
