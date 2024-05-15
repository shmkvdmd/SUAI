<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:template match="/">
        <h2>Игрушки-роботы</h2>
        <table border="1">
            <tr bgcolor="#9acd32">
                <th style="text-align:left">Название</th>
                <th style="text-align:left">Описание</th>
                <th style="text-align:left">Цена</th>
                <th style="text-align:left">Изображение</th>
            </tr>
            <xsl:apply-templates select="toys/toy">
                <xsl:sort select="price"/>
            </xsl:apply-templates>
        </table>
    </xsl:template>

    <xsl:template match="toy">
        <xsl:variable name="price" select="price"/>

        <tr>
            <td>
                <xsl:value-of select="name"/>
            </td>
            <td>
                <xsl:value-of select="description"/>
            </td>
            <td>
                <xsl:if test="$price &gt; 2500">
                    <xsl:attribute name="bgcolor">#FFCCCC</xsl:attribute>
                </xsl:if>
                <xsl:value-of select="price"/>
            </td>
            <td>
                <img src="{image}" alt="{name}" style="width: 100px; height: auto;"/>
            </td>
        </tr>
    </xsl:template>
</xsl:stylesheet>
