Public Class OptionsForm

    Private CallbackForm As MainForm

    Sub New()
        InitializeComponent()
    End Sub

    Sub New(ByVal mainform As Form)
        InitializeComponent()
        CallbackForm = mainform
    End Sub


    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        CallbackForm.SubFormCallback()
        Me.Close()
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        Options.Directory = TextBox1.Text
        Options.SongGap = NumericUpDown1.Value
        Options.PlaylistLength = 1
        CallbackForm.SubFormCallback()
        Me.Close()
    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        If (FolderBrowserDialog1.ShowDialog = Windows.Forms.DialogResult.OK) Then
            TextBox1.Text = FolderBrowserDialog1.SelectedPath
        End If
    End Sub
End Class