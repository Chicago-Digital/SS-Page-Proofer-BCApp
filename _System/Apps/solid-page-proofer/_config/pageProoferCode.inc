{% include "/_System/apps/solid-page-proofer/_data/pageProoferVars.inc" -%}
{% assign devDomain = pageProofer.BCdomain | default: 'businesscatalyst.com' -%}
{% if devDomain == "" -%}{% assign devDomain = 'businesscatalyst.com' -%}{% endif-%}
{% if pageProofer.enabled == "on" -%}
{% capture pageProoferCode -%}
<script type="text/javascript">(function(e,b){var a=e.createElement(b),c=e.getElementsByTagName(b)[0];a.src="//app.pageproofer.com/overlay/js/{{pageProofer.siteID}}/{{pageProofer.accountID}}";a.type="text/javascript";a.async=true;c.parentNode.insertBefore(a,c)})(document,"script");</script>
{% endcapture -%}
{% if this.globals.cookie.siteAuthToken -%}
{{pageProoferCode}}
{% elseif this.globals.site.host contains devDomain -%}
{% unless pageProofer.disableBC == "on" -%}
{{pageProoferCode}}
{% endunless -%}
{% endif -%}
{% endif -%}
{% comment -%}<!-- Set a variable equal to today's date to invalidate the cache -->{% endcomment -%}
{% assign notNeededDate = globals.site.dateNow | date: "yyyy" -%}