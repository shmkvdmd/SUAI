<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <h2>Роботы игрушки</h2>
        <xsl:for-each select="toys/toy">
            <div style="background-color: teal; color: white; padding: 4px">
                <span style="font-weight: bold">
                    <xsl:value-of select="name"/>
                    -
                </span>
                <xsl:value-of select="price"/>
            </div>
            <div style="margin-left: 20px; margin-bottom: 1em; font-size: 14pt">
                <p>
                    <xsl:value-of select="description"/>
                </p>
                <img src="{image}" alt="{name}" style="width: 100px; height: 100px;"/>
            </div>
        </xsl:for-each>
    </xsl:template>
</xsl:stylesheet>
