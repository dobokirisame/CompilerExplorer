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
		auto compilerId = removeSpacesAtEnd(textPair.at(0));
		result.insert({compilerId,textPair.at(1)});
	}
	result.erase(result.begin());
	return result;
}

QString CompilersListReplyParser::removeSpacesAtEnd(const QString &text) const{
	auto newText = text;
	if (newText.endsWith(" ")) {
		newText = newText.mid(0, newText.length() - 1);
		newText = removeSpacesAtEnd(newText);
	}
	return newText;
}

QByteArray CompilersListReplyParser::reply() const {
	return mReply;
}

void CompilersListReplyParser::setReply(const QByteArray &reply) {
	mReply = reply;
}


}
}
