#include "RequestSender.h"
#include "Request.h"

namespace compilerExplorer {
namespace network{

RequestSender::RequestSender(QObject *parent) : QObject(parent) {

}

QByteArray RequestSender::get(Request &request) {

}

QByteArray RequestSender::post(Request &request) {

}

}
}
