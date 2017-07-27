#ifndef KMLPARSER_H
#define KMLPARSER_H

#include <QXmlStreamReader>
#include <QDateTime>
#include "parser.h"

class KMLParser : public Parser
{
public:
	~KMLParser() {}

	bool parse(QFile *file, QList<TrackData> &tracks,
	  QList<RouteData> &routes, QList<Waypoint> &waypoints);
	QString errorString() const {return _reader.errorString();}
	int errorLine() const {return _reader.lineNumber();}

private:
	void kml(QList<TrackData> &tracks, QList<Waypoint> &waypoints);
	void document(QList<TrackData> &tracks, QList<Waypoint> &waypoints);
	void folder(QList<TrackData> &tracks, QList<Waypoint> &waypoints);
	void placemark(QList<TrackData> &tracks, QList<Waypoint> &waypoints);
	void multiGeometry(QList<TrackData> &tracks, QList<Waypoint> &waypoints,
	  const QString &name, const QString &desc, const QDateTime timestamp);
	void track(TrackData &track);
	void lineString(TrackData &track);
	void point(Waypoint &waypoint);
	bool pointCoordinates(Waypoint &waypoint);
	bool lineCoordinates(TrackData &track);
	bool coord(Trackpoint &trackpoint);
	QDateTime timeStamp();
	qreal number();
	QDateTime time();

	QXmlStreamReader _reader;
};

#endif // KMLPARSER_H
