#ifndef ONLINEMAP_H
#define ONLINEMAP_H

#include "common/range.h"
#include "common/rectc.h"
#include "map.h"
#include "tileloader.h"

class OnlineMap : public Map
{
	Q_OBJECT

public:
	OnlineMap(const QString &name, const QString &url, const Range &zooms,
	  const RectC &bounds, const Authorization &authorization,
	  QObject *parent = 0);

	QString name() const {return _name;}

	QRectF bounds();
	qreal resolution(const QRectF &rect);

	int zoom() const {return _zoom;}
	void setZoom(int zoom) {_zoom = zoom;}
	int zoomFit(const QSize &size, const RectC &rect);
	int zoomIn();
	int zoomOut();

	QPointF ll2xy(const Coordinates &c);
	Coordinates xy2ll(const QPointF &p);

	void draw(QPainter *painter, const QRectF &rect, bool block);

	void clearCache() {_tileLoader->clearCache();}

	bool isValid() const {return _valid;}
	QString errorString() const {return _errorString;}

private:
	int limitZoom(int zoom) const;

	TileLoader *_tileLoader;
	QString _name;
	Range _zooms;
	RectC _bounds;
	int _zoom;

	bool _valid;
	QString _errorString;
};

#endif // ONLINEMAP_H
