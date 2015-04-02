Public Class FileData

    Sub New(fileName As String, fileTime As String)
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
        Dim out As String = Me.FileName & " - [" & Me.FileTime.ToString() & "]"
        Return out
    End Function



End Class
