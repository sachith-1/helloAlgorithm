function Get-Maximum {
    <#
    .SYNOPSIS
        Returns the largest value of a number seriess.

    .DESCRIPTION
        Returns the largest value of a number series.
        It is possible to specify an Int array or comma separated integers.

    .PARAMETER values
        Int array or comma separated integers

    .INPUTS
        None. You cannot pipe objects to Add-Extension.

    .OUTPUTS
        Int32

    .EXAMPLE
        Get-Maximum -values @(45, 65, 221, 5, 22)
        Get-Maximum -values 1, 99, 22

    #>
    param(
        [Parameter(Mandatory = $true)]
        [AllowEmptyCollection()]
        [int[]]
        #List with integers (array or comma separated).
        $values
    )

    ($values | measure -Maximum).Maximum
}

Get-Maximum -values @(45, 65, 221, 5, 22)
Get-Maximum -values 1, 99, 22
Get-Help -Name Get-Maximum
