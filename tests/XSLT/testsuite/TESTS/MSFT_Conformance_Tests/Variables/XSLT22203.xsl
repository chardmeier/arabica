<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
    <xsl:param name="x"></xsl:param>
    <xsl:template match="/">
        
******
        <xsl:value-of select="$x"></xsl:value-of>
        ******
	
    </xsl:template>
</xsl:stylesheet>
