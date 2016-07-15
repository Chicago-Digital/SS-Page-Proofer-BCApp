{% include "/_System/apps/solid-page-proofer/_data/pageProoferVars.inc" -%}
{% unless pageProofer.BCdomain -%}{% assign pageProofer.BCdomain = 'businesscatalyst.com' -%}{% endunless -%}
{% if pageProofer.enabled == "on" -%}
{% capture pageProoferCode -%}
<script type="text/javascript">
(function (d, t) {
   var pp = d.createElement(t), s = d.getElementsByTagName(t)[0];
    pp.src = '//app.pageproofer.com/overlay/js/{{pageProofer.siteID}}/{{pageProofer.accountID}}';
   pp.type = 'text/javascript';
   pp.async = true;
   s.parentNode.insertBefore(pp, s);
})(document, 'script');
</script>
{% endcapture -%}                                
	{% if this.globals.cookie.siteAuthToken -%}
	{{pageProoferCode}}
	{% elseif this.globals.site.host contains pageProofer.BCdomain -%}
		{% unless pageProofer.disableBC == "on" -%}
		{{pageProoferCode}}
		{% endunless -%}
	{% endif -%}
	{% endif -%}