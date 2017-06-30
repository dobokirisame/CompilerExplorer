#include "RequestSender.h"
#include "Request.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include <QEventLoop>

const int timeout = 15000;

namespace compilerExplorer {
namespace network{

RequestSender::RequestSender(QObject *parent) :
    QObject(parent),
    mManager(new QNetworkAccessManager(this)) {

}

QByteArray RequestSender::sendRequest(Request *request) const {
	QTimer timer;
	timer.setInterval(timeout);
	timer.setSingleShot(true);

	QEventLoop loop;
	auto reply = request->sendRequest(mManager);
	connect(reply.get(), &QNetworkReply::finished, &loop, &QEventLoop::quit);
	connect(&timer, &QTimer::timeout, reply.get(), &QNetworkReply::abort);
	timer.start();
	loop.exec();

	QByteArray result;
	if (reply->isFinished() && reply->error() == QNetworkReply::NoError) {
		result = reply->readAll();
	}
	return result;
}

}
}
