#!/bin/bash

setPackageManager() {
   local command

   for command in /sbin/apk /usr/bin/dnf /usr/bin/dpkg /usr/sbin/pkg /usr/bin/zypper
   do
      [ -x "${command}" ] && {
         declare -g -r packageManager="${command##*/}"
         return 0
      }
   done

   semanticError "unknown package manager"
}

unsupportedPackageOperation() {
   semanticError "unsupported package operation"
}

listInstalledPackages_apk() {
   apk list --installed | awk '
      {
         gsub(/-[0-9].*/, "", $1)
         print $1
      }
   ' | sort -u
}

installPackages_apk() {
   apk add --quiet --no-progress -- "${@}"
}

removePackages_apk() {
   apk del --quiet --no-progress -- "${@}"
}

describePackage_apk() {
   apk info -- "${@}"
}

whichPackage_apk() {
   unsupportedPackageOperation
}

searchPackage_apk() {
   apk search --description -- "${@}"
}

listInstalledPackages_dnf() {
   rpm --query --all --queryformat '%{NAME}\n'
}

installPackages_dnf() {
   dnf -y --quiet install "${@}"
}

removePackages_dnf() {
   dnf -y --quiet remove "${@}"
}

describePackage_dnf() {
   dnf --quiet info "${1}"
}

whichPackage_dnf() {
   dnf --quiet whatprovides "${1}"
}

searchPackage_dnf() {
   dnf --quiet search "${1}"
}

listInstalledPackages_dpkg() {
   dpkg-query --show --showformat '${Package}\n'
}

installPackages_dpkg() {
   apt --yes --quiet --quiet --quiet install "${@}"
}

listInstalledPackages_pkg() {
   pkg query --all "%n"
}

installPackages_pkg() {
   pkg --quiet install "${@}"
}

listInstalledPackages_zypper() {
   zypper --quiet packages --installed-only | awk --field-separator "|" '
      NR > 2 {
         sub(/^\s*/, "", $3)
         sub(/\s*$/, "", $3)
         print $3
      }
   ' | sort -u
}

installPackages_zypper() {
   zypper --quiet install --no-confirm -- "${@}"
}

normalizePackageList() {
   sort | uniq
}

listInstalledPackages() {
   "listInstalledPackages_${packageManager}"
}

installPackages() {
   "installPackages_${packageManager}" "${@}"
}

removePackages() {
   "removePackages_${packageManager}" "${@}"
}

describePackage() {
   "describePackage_${packageManager}" "${1}"
}

whichPackage() {
   "whichPackage_${packageManager}" "${1}"
}

searchPackage() {
   "searchPackage_${packageManager}" "${1}"
}

setPackageManager
