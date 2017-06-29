#ifndef REQUESTSENDER_H
#define REQUESTSENDER_H

#include <QObject>


namespace compilerExplorer {
namespace network{
class Request;

class RequestSender : public QObject
{
	Q_OBJECT
public:
	explicit RequestSender(QObject *parent = nullptr);
public slots:
	QByteArray get(Request& request);
	QByteArray post(Request& request);

signals:

public slots:
};
}
}
#endif // REQUESTSENDER_H
