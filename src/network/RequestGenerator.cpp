#include "RequestGenerator.h"
#include "GetRequest.h"
#include "PostJsonRequest.h"
#include <QSettings>
#include "compilerexplorerconstants.h"

namespace compilerExplorer {
namespace network{
const QString compilerLocationKey = "compiler";
const QString compilerOptionsKey = "options";
const QString sourceCodeKey = "source";
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

RequestGenerator::RequestGenerator()
    : RequestGenerator(QString(), 0) {
}

RequestGenerator::RequestGenerator(const QString &address, const int port)
    : d(std::make_unique<RequestGeneratorPrivate>()) {
	d->address = address;
	d->port = port;
}

RequestGenerator::~RequestGenerator() {
}

Request *RequestGenerator::createCompilerRequest() {
	PostJsonRequest *result = new PostJsonRequest();
	result->setAddress(QString("%1:%2/%3").arg(d->address).arg(d->port).arg(d->compilerLocation));
	result->addParameter(compilerLocationKey, d->compilerLocation);
	result->addParameter(sourceCodeKey, d->sourceCode);
	result->addParameter(compilerOptionsKey, d->compilerOptions);
	result->setFilters(d->filters);
	result->setFiltersKey(filtersKey);
	return std::move(result);
}

QString RequestGenerator::address() const {
	return d->address;
}

void RequestGenerator::setAddress(const QString &address) {
	d->address = address;
}

int RequestGenerator::port() const {
	return d->port;
}

void RequestGenerator::setPort(const int port){
	d->port = port;
}

void RequestGenerator::setCompilerLocation(const QString &location) {
	d->compilerLocation = location;
}

void RequestGenerator::setCompilerOptions(const QString &options) {
	d->compilerOptions = options;
}

void RequestGenerator::setSourceCode(const QString &code) {
	d->sourceCode = code;
}

void RequestGenerator::setFilters(const QStringList &filters) {
	d->filters = filters;
}

void RequestGenerator::updateSettings(const QSettings &settings) {
	const auto useLocalServer = settings.value(constants::useLocalServerKey).toBool();
	QString address;
	int port;
	if(useLocalServer) {
		address = "http://localhost";
		port = settings.value(constants::localServerPortKey).toInt();
	} else {
		address = settings.value(constants::remoteServerUrlKey).toString();
		port = 80;
	}
	setAddress(address);
	setPort(port);
}

std::unique_ptr<Request> RequestGenerator::comilersListRequest(const QString &address, const int port) {
	auto result = std::make_unique<GetRequest>();
	result->setAddress(QString("%1:%2/api/compilers").arg(address).arg(port));
	return std::move(result);
}
}
}
