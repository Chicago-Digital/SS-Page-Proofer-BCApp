{% include "/_System/apps/solid-page-proofer/_data/pageProoferVars.inc" -%} {% if pageProofer.BCdomain == "" -%}{% assign BCdomain = "businesscatalyst.com" -%}
{% else -%} {% assign BCdomain = pageProofer.BCdomain -%} {% endif -%} {% if pageProofer.enabled == "on" -%} {% capture pageProoferCode -%}
<script type="text/javascript">var PageProoferConfig = {'email': '{{globals.cookie.UN}}'};(function(d, t) {var pp = d.createElement(t),s = d.getElementsByTagName(t)[0];pp.src = '//app.pageproofer.com/overlay/js/{{pageProofer.siteID}}/{{pageProofer.accountID}}';pp.type = 'text/javascript';pp.async = true;s.parentNode.insertBefore(pp, s);})(document, 'script');</script>
{% endcapture -%} {% capture loggedInCheck -%}{{globals.cookie.UN}}{% endcapture -%} {% if loggedInCheck != "" -%} {{pageProoferCode}} {% elseif this.globals.site.host contains BCdomain -%}
{% unless pageProofer.disableBC == "on" -%} {{pageProoferCode}} {% endunless -%} {% endif -%} {% endif -%}
{% comment -%}<!-- Set a variable equal to today's date to invalidate the cache -->{% endcomment -%}
{% assign notNeededDate = globals.site.dateNow | date: "yyyy" -%}