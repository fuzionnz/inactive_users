Inactive Users
==============

Inactive Users contains features to assist in managing registration and contact signup spam on Drupal sites.

Initially a view and a couple of hooks to remove associated contacts.

## Rationale

Registration spam pushes the task of managing removals onto site admins. Unless it's possible to prevent rego spam (hint: don't accept registrations!) or to automatically remove all regos (not suited for many sites), we need to do something to make the admin's life better when doing this task.

We work with CiviCRM sites a lot, so initially we're looking at it in relation to CiviCRM contacts and we're connecting the user and contact data accordingly. If your site isn't a CiviCRM site, this module may not be for you (yet).

## TODO

* Better filters. I'd like admins to be able to use exposed filters to identify familiar patterns -
 * Users who haven't validated their email.
 * Users whose name fields contain spammy-looking data (right now we're seeing street addresses in names).
 * Users without associated CiviCRM contacts.
 * Users whose Drupal and CiviCRM emails differ.
 * Users who have never logged in.
* Rename module. "Inactive Users" isn't quite right.
* Push some of these features back to CiviCRM project (?).
* Improve data displayed in table (how else can we identify spammers?)
* Display IP the user registered from as a column.
