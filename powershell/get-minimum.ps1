function Get-Minimum {
    <#
    .SYNOPSIS
        Returns the smallest value of a number series.

    .DESCRIPTION
        Returns the smallest value of a number series.
        It is possible to specify an Int array or comma separated integers.

    .PARAMETER values
        Int array or comma separated integers

    .INPUTS
        None. You cannot pipe objects to Add-Extension.

    .OUTPUTS
        Int32

    .EXAMPLE
        Get-Minimum -values @(45, 65, 221, 5, 22)
        Get-Minimum -values 1, 99, 22

    #>
    param(
        [Parameter(Mandatory = $true)]
        [AllowEmptyCollection()]
        [int[]]
        #List with integers (array or comma separated).
        $values
    )

    [int]($values | measure -Minimum).Minimum
}

Get-Minimum -values @(45, 65, 221, 5, 22)
Get-Minimum -values 1, 99, 22
Get-Help -Name Get-Minimum
