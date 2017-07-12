#include "CompilersListReplyParser.h"
#include <QTextCodec>
#include <QDebug>

namespace compilerExplorer {
namespace network{

CompilersListReplyParser::CompilersListReplyParser(const QByteArray &reply)
    : mReply(reply){

}

std::map<QString, QString> CompilersListReplyParser::parse(QByteArray reply) {
	CompilersListReplyParser parser(reply);
	return parser.parseReply();
}

std::map<QString, QString> CompilersListReplyParser::parseReply() {
	std::map<QString, QString> result;
	if(reply().isEmpty())
		return result;
	auto textReply = QTextCodec::codecForMib(106)->toUnicode(reply());
	auto items = textReply.split('\n');
	if(items.size() < 1) {
		return result;
	}
	for(const auto &item : items) {
		auto textPair = item.split(" | ");
		if(textPair.size() != 2) {
			qInfo() << "Strange compiler pair in reply: " << textPair;
			return result;
		}
		result.insert({textPair.at(0),textPair.at(1)});
	}
	result.erase(result.begin());
	return result;
}

QByteArray CompilersListReplyParser::reply() const {
	return mReply;
}

void CompilersListReplyParser::setReply(const QByteArray &reply) {
	mReply = reply;
}


}
}
