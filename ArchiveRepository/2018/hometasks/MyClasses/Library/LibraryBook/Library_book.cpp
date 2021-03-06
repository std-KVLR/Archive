t
    {
        if (isIndexed())
            return screenIndices_.size() / 3;
        else
            return screenVertices_.size() / 3;
    }

    inline void clear() { firstPointOffset_ = QPointF(0,0);
                          screenVertices_.clear(); screenIndices_.clear(); }

    void allocateAndFill(QSGGeometry *geom) const;

    double geoDistanceToScreenWidth(const QGeoMap &map,
                                           const QGeoCoordinate &fromCoord,
                                           const QGeoCoordinate &toCoord);

    static QRectF translateToCommonOrigin(const QList<QGeoMapItemGeometry *> &geoms);


protected:
    bool sourceDirty_;
    bool screenDirty_;
    bool clipToViewport_;
    bool preserveGeometry_;
    QGeoCoordinate geoLeftBound_;

    QPointF firstPointOffset_;

    QPainterPath screenOutline_;

    QRectF sourceBounds_;
    QRectF screenBounds_;

    QGeoCoordinate srcOrigin_;

    QVector<QPointF> screenVertices_;
    QVector<quint32> screenIndices_;
};

QT_END_NAMESPACE

#endif // QGEOMAPITEMGEOMETRY_H
                                                                                                                                                                                                                                                                                                                