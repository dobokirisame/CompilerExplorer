#include "RequestGenerator.h"
#include "GetRequest.h"

namespace compilerExplorer {
namespace network{
const QString compilerLocationKey = "compiler";
const QString compilerOptionsKey = "options";
const QString sourceCodeKey = "compiler";
const QString filtersKey = "filters";

class RequestGeneratorPrivate
{
public:
	RequestGeneratorPrivate() {}
	QString address;
	int port;
	QString compilerLocation;
	QString compilerOptions;
	QString sourceCode;
	QStringList filters;
};

RequestGenerator::RequestGenerator(const QString &address, const int port)
    : d(new RequestGeneratorPrivate) {

}

RequestGenerator::~RequestGenerator() {
	delete d;
}

Request *RequestGenerator::createCompilerRequest() {

}

Request *RequestGenerator::comilersListRequest(const QString &address, const int port) {
	GetRequest *result = new GetRequest();
	result->setAddress(QString("%1:%2/api/compilers").arg(address).arg(port));
	return std::move(result);
}
}
}
