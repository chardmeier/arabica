<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">

  <!-- FileName: str51 -->
  <!-- Document: http://www.w3.org/TR/xpath -->
  <!-- DocVersion: 19990922 -->
  <!-- Section: 4.2 String Functions -->
  <!-- Purpose: Test of 'starts-with()' function with node. -->

<xsl:template match="doc">
	<out>
		<xsl:value-of select="starts-with(doc, 'ENCY')"/>
	</out>
</xsl:template>

</xsl:stylesheet>