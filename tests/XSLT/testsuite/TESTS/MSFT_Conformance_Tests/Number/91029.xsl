<!-- XSLT - Numbering - Counting  from a context node that is not an element - level = "any" & "single" & "multiple" -->
<!-- count = "node()" - from -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/19/2000 -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:my="http://my.com">
<xsl:output encoding="UTF-8" indent="yes" omit-xml-declaration="yes"/>

	<xsl:template match="/">

        <xsl:text>&#13;&#10;&#13;&#10;Processing Instruction()&#13;&#10;</xsl:text>
        <xsl:apply-templates select="processing-instruction() | comment() | //book/@style" mode="nodetype-tests"/>

	</xsl:template>


     <!-- Test counting where original node is not an element -->
     <xsl:template match="node() | @*" mode="nodetype-tests">

        <xsl:text>&#13;&#10;</xsl:text>
        <xsl:number level="any" count="node() | /"/><xsl:text>, </xsl:text>
        <xsl:number level="any" count="node() | /" from="*"/><xsl:text>, </xsl:text>
        <xsl:number level="any" count="node() | /" from="@*"/><xsl:text>, </xsl:text>

        <xsl:number level="multiple" count="node() | /"/><xsl:text>, </xsl:text>
        <xsl:number level="multiple" count="node() | /" from="bookstore"/><xsl:text>, </xsl:text>
        <xsl:number level="multiple" count="node() | /" from="@*"/><xsl:text>, </xsl:text>
        
        <xsl:number level="single" count="node() | /"/><xsl:text>, </xsl:text>
        <xsl:number level="single" count="node() | /" from="bookstore"/><xsl:text>, </xsl:text>
        <xsl:number level="single" count="node() | /" from="@*"/><xsl:text>, </xsl:text>
    
    </xsl:template>

</xsl:stylesheet>
	
 
 