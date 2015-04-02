Public Class FileData

    Sub New(fileName As String, fileTime As Integer)
        Me.FileName = fileName
        Me.FileTime = fileTime
    End Sub

    Private _FileName As String
    Public Property FileName() As String
        Get
            Return _FileName
        End Get
        Set(ByVal value As String)
            _FileName = value
        End Set
    End Property

    Private _FileTime As Integer
    Public Property FileTime() As Integer
        Get
            Return _FileTime
        End Get
        Set(ByVal value As Integer)
            _FileTime = value
        End Set
    End Property

    Overrides Function ToString() As String
        Dim formattedTime As String = String.Empty
        Dim iSpan As TimeSpan = TimeSpan.FromSeconds(Me.FileTime)
        If iSpan.Hours > 0 Then
            formattedTime = iSpan.Hours.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        Else
            formattedTime = iSpan.Minutes.ToString.PadLeft(2, "0"c) & ":" & _
                    iSpan.Seconds.ToString.PadLeft(2, "0"c)
        End If

        Dim out As String = Me.FileName & " - [" & formattedTime & "]"

        Return out
    End Function



End Class
